function [img, br, bc, d] = padding(I)
    [r c d] = size(I);
    br = r/8;
    bc = c/8;
    if br <> int(br) then
        br = ceil(br);
    end
    if bc <> int(bc) then
        bc = ceil(bc);
    end
    r = 8*br;
    c = 8*bc;
    for i = 1:d     // zero padding if required
        img(:,:,i) = resize_matrix(I(:,:,i), r, c);
    end
endfunction

function [arr, len] = compress(I, func)
    [img br bc d] = padding(I);
    
    if d > 1 then // channel conversion
        img = rgb2ycbcr(img);
        // Chrominance downsampling
        for i = 2:3
            img(:,:,i) = 2 * round(img(:,:,i)./2);
        end
    end
    
    for k = 1:d
        for i = 1:br
            for j = 1:bc
                ib = double(img(i*8-7:i*8, j*8-7:j*8, k)) - 128;
                t_b = func(ib);
                zcoef = rle(zigzag(quantize(t_b, k)), %t);
                arr{i,j} = zcoef;
                /*iz = izigzag(zcoef, 8,8);
                iq_b = quantize(iz, channel = k, enc = %f);
                invb = round(ifunc(iq_b) + 128);
                img(i*8-7:i*8, j*8-7:j*8, k) = invb;*/
            end 
        end
    end
    len = 0;
    for i = 1:br
        for j = 1:bc
            len = len + length(arr{i,j});
        end
    end
endfunction

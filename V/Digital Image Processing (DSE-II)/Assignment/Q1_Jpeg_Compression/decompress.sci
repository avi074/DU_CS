// 3. DWT Compress

function [CA, i1] = wave_compress(img, r, c, level)
    i1 = double(img);
    CA = zeros(r, c, 'uint8');
    
    for i = 1:level
        s = stdev(i1(:));
        [ca ch cv cd] = dwt2(i1, 'haar');
        ca(ca < s) = 0;
        ch(ch < s) = 0;
        cv(cv < s) = 0;
        cd(cd < s) = 0;
        
        i1 = ca;
        CA(1:r/(2^i), 1:c/(2^i)) = ca;
        CA((1+ r/(2^i)):r/(2^(i-1)), 1:c/(2^i)) = cv;
        CA(1:r/(2^i), (1+ c/(2^i)) : c/(2^(i-1))) = ch;
        CA((1+ r/(2^i)):r/(2^(i-1)), (1+ c/(2^i)) : c/(2^(i-1))) = cd;
    end
    CAA = CA;
    for i = level:-1:1
        ca = CAA(1:r/(2^i), 1:c/(2^i));
        cv = CAA((1 + r/(2^i)):r/(2^(i-1)), 1:c/(2^i));
        ch = CAA(1:r/(2^i), (1+ c/(2^i)) : c/(2^(i-1)));
        cd = CAA((1+ r/(2^i)):r/(2^(i-1)), (1+ c/(2^i)) : c/(2^(i-1)));
        
        [i1]= idwt2(ca, ch, cv, cd, 'haar');
        CAA(1:r/2^(i-1), 1:c/2^(i-1)) = i1;
    end
endfunction

function [mse, psnr] = compression_params(oi, ci)
/*
    // @inputs
    //      oi = Original Image Data
    //      ci = Compressed Image Data
    //
    // @returns
    //      mse = Mean Square Error
    //      psnr = Peak Signal to Noise Ratio
    //
    //
    //      for better compression / reconstruction of image 
    //      1. mse should be low.
    //      2. psnr should be high.
    //      
*/
    
    oi = double(oi);
    ci = double(ci);
    [h,w] = size(oi); 

    mse = sum((oi - ci).^2)/(h*w);
    psnr = 10 * log10(255*255/mse);
endfunction

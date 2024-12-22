function q_block = quantize(iblock, channel, qf, enc)
    /*
    // @args
    //      iblock = image block of size 8 x 8
    //      channel = image channels if its RGB
    //      qf = quality factor
    //      enc = encoding boolean
    //
    // @returns
    //      qblock = quantized block
    //  
    // @description
    //      Perform quantization or dequantization on the 8 x 8 block
    // of image & round off the resultant double matrix
    */
    
    if ~exists('channel', 'local') then channel = 1; end
    if ~exists('qf', 'local') then qf = 1; end
    if ~exists('enc', 'local') then enc = %t; end
    
    // Luminance Matrix
    Qy = [16 11 10 16 24 40 51 61;
         12 12 14 19 26 28 60 55 ;
         14 13 16 24 40 57 69 56 ;
         14 17 22 29 51 87 80 62 ;
         18 22 37 56 68 109 103 77;
         24 35 55 64 81 104 113 92;
         49 64 78 87 103 121 120 101;
         72 92 95 98 112 100 103 99]; 
    
    // Chrominance Matrix
    Qc = [17 18 24 47 99 99 99 99;
         18 21 26 66 99 99 99 99;
         24 26 56 99 99 99 99 99;
         47 66 99 99 99 99 99 99;
         99 99 99 99 99 99 99 99;
         99 99 99 99 99 99 99 99;
         99 99 99 99 99 99 99 99;
         99 99 99 99 99 99 99 99];
     
     Qy = Qy.*qf;
     Qc = Qc.*qf;
     
     if enc then
         if channel == 1 then 
             q_block = round(iblock./Qy);
         else 
             q_block = round(iblock./Qc);
         end
     else
        if channel == 1 then 
            q_block = iblock.*Qy;
         else 
             q_block = iblock.*Qc;
         end
     end
endfunction

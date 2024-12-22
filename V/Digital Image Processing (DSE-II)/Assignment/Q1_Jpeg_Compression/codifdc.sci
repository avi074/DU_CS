function [code1] = codeValue(diff)
    code1 = dec2bin(abs(diff));   
    
    if diff < 0
        num = strtod(code1);
        s = "";
        for i=1:length(code1)
            mod = int(modulo(num,10));
            num = num/10;
            if mod == 1 then
                s ='0' + s;
            else
                s ='1' + s;
            end
        end
        code1 = s;
    end
endfunction



function [codeDc] = codifdc(diff)
    // Finding Category
    
    if (diff==0) then
        category = 0;
        code = '0';

    elseif (abs(diff)==1) then
        category = 1;
        code = '010';

    elseif ((abs(diff)==2)||(abs(diff)==3)) then
        category = 2;
        code = '011';

    elseif ((4 <= abs(diff))&&(abs(diff) <= 7)) then
        category = 3;
        code = '100';

    elseif ((8 <= abs(diff))&&(abs(diff) <= 15)) then
        category= 4;
        code = '101';

    elseif ((16 <= abs(diff))&&(abs(diff) <= 31)) then
        category = 5;
        code = '110';

    elseif ((32 <= abs(diff))&&(abs(diff) <= 63)) then
        category= 6;
        code = '1110';

    elseif ((64 <= abs(diff))&&(abs(diff) <= 127)) then
        category = 7;
        code = '11110';

    elseif ((128 <= abs(diff))&&(abs(diff) <= 255)) then
        category= 8;
        code = '111110';

    elseif ((256 <= abs(diff))&&(abs(diff) <= 511)) then
        category = 9;
        code = '11111110';

    elseif ((512 <= abs(diff))&&(abs(diff) <= 1023)) then
        category= 10;
        code = '11111110';
    
    else
        category= 11;
        code = '111111110';
    end
    code1 = codeValue(diff);
    if (diff <> 0)
        codeDc = [code code1];
    else
        codeDc = [code];
    end
endfunction

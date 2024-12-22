function out = rle(vec, enc)
    len = length(vec);
    counter=0;  out = []; i=1;
    
    if enc then
         while i <= len
            if vec(i) == 0
               while vec(i) == 0
                counter=counter+1;
                i=i+1;
                if i > len  break; end
               end
                out = [out 0 counter];
                counter=0;
            else
                out = [out vec(i)];
                i=i+1;
            end
        end
    else
        while i<=len
            if vec(i)==0 
                out = [out zeros(1,vec(i+1))];
                i = i + 2;
            else
               out = [out vec(i)];
               i=i+1;
            end
       end
    end
endfunction

function arr = zigzag(block)
    /*
    // @args
    //      block = 2D matrix of double / constant
    //
    // @returns
    //      arr = 1D array / vector
    //
    // @description
    //      pick elements from matrix block & save it in 
    // 1D array in linear format.
    */
    
    [n_row, n_col] = size(block);
    c_row = 1; c_idx = 1; c_col = 1;
    arr = zeros(1, n_row * n_col);
    
    while c_row <= n_row & c_col <= n_col
        if modulo(c_row + c_col, 2) == 0 
            then
            if c_row == 1 & c_col <> n_col 
                then
                arr(c_idx) = block(c_row, c_col); // insert element
                c_idx = c_idx + 1; // update index
                c_col = c_col + 1; // right shift on 1st row
                
            elseif c_col == n_col & c_row <> n_row
                then
                arr(c_idx) = block(c_row, c_col); 
                c_idx = c_idx + 1; 
                c_row = c_row + 1; // down shift on last col
             
            else
                arr(c_idx) = block(c_row, c_col); 
                c_idx = c_idx + 1;
                c_row = c_row - 1; c_col = c_col + 1; // diagonal upward shift
            end
            
        else
            if c_col == 1 & c_row <> n_row 
                then
                arr(c_idx) = block(c_row, c_col); // insert element
                c_idx = c_idx + 1; // update index
                c_row = c_row + 1; // down shift on 1st col
                
            elseif c_row == n_row & c_col <> n_col
                then
                arr(c_idx) = block(c_row, c_col); 
                c_idx = c_idx + 1; 
                c_col = c_col + 1; // right shift on last row
             
            else
                arr(c_idx) = block(c_row, c_col); 
                c_idx = c_idx + 1;
                c_row = c_row + 1; c_col = c_col - 1; // diagonal downward shift
            end
        end
        
        if c_row == n_row & c_col == n_col then 
            arr(c_idx) = block(c_row, c_col);
            break;
        end
    end
    
    for i = 1:n_row*n_col
        if arr(i) <> 0 then
            c_idx = i;
        end
    end
    arr = arr(1:c_idx);
endfunction

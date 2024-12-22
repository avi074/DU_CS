function [block] = izigzag(arr, n_row, n_col)
    /*
    // @args
    //      arr = 1D array / vector of size(1, n_row * n_col)
    //      n_row = total no. of rows
    //      n_col = total no. of cols
    //
    // @returns
    //      block = 2D matrix of size(n_row, n_col)
    //
    // @description
    //      pick elements from 1D zigzaged array & save it in 
    //  M x N matrix block.
    */
    c_row = 1; c_idx = 1; c_col = 1;
    block = zeros(n_row, n_col);
    arr = resize_matrix(arr, 1, n_row*n_col);
    
    while c_row <= n_row & c_col <= n_col
        if modulo(c_row + c_col, 2) == 0 
            then
            if c_row == 1 & c_col < n_col 
                then
                block(c_row, c_col) = arr(c_idx); // insert element
                c_idx = c_idx + 1; // update index
                c_col = c_col + 1; // right shift
                
            elseif c_col == n_col & c_row < n_row
                then
                block(c_row, c_col) = arr(c_idx) 
                c_idx = c_idx + 1; 
                c_row = c_row + 1; // down shift
             
            else
                block(c_row, c_col) = arr(c_idx) 
                c_idx = c_idx + 1;
                c_row = c_row - 1; c_col = c_col + 1; // diagonal upward shift
            end
            
        else
            if c_col == 1 & c_row <> n_row 
                then
                block(c_row, c_col) = arr(c_idx); // insert element
                c_idx = c_idx + 1; // update index
                c_row = c_row + 1; // down shift on 1st col
                
            elseif c_row == n_row & c_col < n_col
                then
                block(c_row, c_col) = arr(c_idx);
                c_idx = c_idx + 1; 
                c_col = c_col + 1; // right shift on last row
             
            else
                block(c_row, c_col) = arr(c_idx);
                c_idx = c_idx + 1;
                c_row = c_row + 1; c_col = c_col - 1; // diagonal downward shift
            end
        end         
        
        if c_row == n_row & c_col == n_col then 
            block(c_row, c_col) = arr(c_idx);
            break;
        end
    end
endfunction

function level = otsu_threshold(I)
// Calculate Otsu's Global threshold value
//    
// @args
//    I : Source Image
//
// @returns
//    level : Otsu's threshold value
//
// @description
//    The function uses Otsu's method, which chooses the threshold to
//    minimize the intraclass variance of the black and white pixels.     
// If the image is RGB convert it to grayscale
if (size(I,3) == 3) then
    I = rgb2gray(I);
end

// Calculation of the normalized histogram
n = 256;
h = imhist(I(:), n);        
h = h/(length(I(:)) + 1);

// Calculation of the cumulated histogram and the mean values
w = cumsum(h);
mu = zeros(n, 1); 
mu(1) = h(1);
for i=2:n
    mu(i) = mu(i-1) + i*h(i);
end    

// Initialisation of the values used for the threshold calculation
level = find (h > 0, 1);
w0 = w(level);
w1 = 1-w0;
mu0 = mu(level)/w0;
mu1 = (mu($)-mu(level))/w1;
maxval = w0*w1*(mu1-mu0)*(mu1-mu0);

// For each step of the histogram
// calculation of the threshold and storing of the maximum
for i = find (h > 0)
    w0 = w(i);
    w1 = 1-w0;
    mu0 = mu(i)/w0;
    mu1 = (mu($)-mu(i))/w1;
    s = w0*w1*(mu1-mu0)*(mu1-mu0);
    if (s > maxval)
        maxval = s;
        level = i;
    end
end

// Normalisation of the threshold        
level = level./n;
endfunction

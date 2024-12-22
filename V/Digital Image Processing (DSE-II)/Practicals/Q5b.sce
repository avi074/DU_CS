g_img = imread('Test_images/girlface.bmp');
[mr, nc] = size(g_img);
eq_img = zeros(mr, nc, 'uint8');
/* Algorithm */
[freq, bins] = imhist(g_img,256);
bins = 255;
freq = cumsum(freq);
npixels = prod(size(g_img));
probc = freq./npixels;
output = round(bins.*probc);

// Creating Equalized Image
for i = 1:mr
    for j = 1:nc
        eq_img(i,j) = output(g_img(i,j) + 1);
    end,
end;

subplot(1,2,1),title("Equalized Image "),imshow(eq_img);
subplot(1,2,2),title("Histogram Equalization"),imhist(g_img,[],1);

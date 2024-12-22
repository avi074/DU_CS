/* a. With standard Matlab function *\/

lena_img = imread(fullpath(getIPCVpath() + "/images/Lena_dark.png"));
he_img = imhistequal(lena_img);

figure(1);
subplot(2,2,1),title("Original Image "),imshow(lena_img);
subplot(2,2,2),title("Original Histogram"),imhist(lena_img,[],1);
subplot(2,2,3),title("Equalized Image "),imshow(he_img);
subplot(2,2,4),title("Equalized Histogram"),imhist(he_img,[],1);


/* b. Without standard Matlab function */ 

g_img = imread('Test_images/girlface.bmp');

function eq_img = histeq(g_img)
    [f, bins] = imhist(g_img,256);
    bins = 255;
    npixels = prod(size(g_img));
    [mr, nc] = size(g_img);
    f = cumsum(f);
    output = round(bins*(f./npixels));

    // Creating Equalized Image
    for i = 1:mr
        for j = 1:nc
            eq_img(i,j) = output(g_img(i,j) + 1);
        end,
    end;
    eq_img = uint8(eq_img);
endfunction;

he_img = histeq(g_img);
figure(1);
subplot(2,2,1),title("Original Image "),imshow(g_img);
subplot(2,2,2),title("Original Histogram"),imhist(g_img,[],1);
subplot(2,2,3),title("Equalized Image "),imshow(he_img);
subplot(2,2,4),title("Histogram Equalization"),imhist(he_img,[],1);

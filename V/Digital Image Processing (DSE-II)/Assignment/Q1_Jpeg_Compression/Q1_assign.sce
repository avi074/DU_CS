// Load all the files
funcprot(0);
path = get_absolute_file_path();
exec(fullpath(path + 'compress.sci'), -1);
exec(fullpath(path + 'quantization.sci'), -1);
exec(fullpath(path + 'zigzag.sci'), -1);
exec(fullpath(path + 'izigzag.sci'), -1);
exec(fullpath(path + 'rle.sci'), -1);
exec(fullpath(path + 'decompress.sci'), -1);

img = imread(fullpath(getIPCVpath() + 'images/Lena_dark.png'));
[r c d] = size(img);

[comp_arr, tpix] = compress(img, dct);
[comp_ar1, tpix1]= compress(img, fft);

img1 = decompress(comp_arr, ceil(r/8), ceil(c/8), d, idct);
img2 = decompress(comp_ar1, ceil(r/8), ceil(c/8), d, ifft);
//img3 = wave_compress(img, );
c1 = prod(size(img))/tpix;
c2 = prod(size(img))/tpix1;

printf("\nDCT Compression Ratio : %.2f \n\tRedundancy : %.2f", c1, 1 - (1/c1));
printf("\n\nFFT Compression Ratio : %.2f \n\tRedundancy : %.2f", c2, 1 - (1/c2));

subplot(221), title('Original Image'), imshow(img);
subplot(222), title('DCT Decompressed Image'), imshow(img1);
subplot(223), title('FFT Decompressed Image'), imshow(img2);
subplot(224), title('DWT Decompressed Image'), imshow(img3);

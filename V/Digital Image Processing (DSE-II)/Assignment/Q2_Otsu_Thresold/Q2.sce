exec(fullpath(get_absolute_file_path() + 'otsu_threshold.sci'), -1);
// load the image
img = imread(fullpath(getIPCVpath() + 'images/lena.png'));
img = rgb2gray(img);
subplot(2,1,1), title('Original Image'), imshow(img);

th = otsu_threshold(img);
bw = im2bw(img, th);
subplot(2,1,2);
title('Thresholded Image by Otsu''s method at T =' + string(th*256));
imshow(bw);

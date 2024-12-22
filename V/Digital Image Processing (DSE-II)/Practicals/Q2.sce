/* a. Obtaining Negative Image */

// for negative image use '~' operator or imcomplement() method
// neg_img = 255 - img
n = 1;

img = imread('Test_images/download.jpeg');
neg_img = 255 - img;

figure(n), n = n + 1;
subplot(1,2,1), title('Original Image'), imshow(img);
subplot(1,2,2), title('Negative Image'), imshow(neg_img);


/* b. Obtaining flipped images */

figure(n), n = n + 1;
subplot(2,2,1), title('Original Image'), imshow(img);
subplot(2,2,3), title('Up to Down Flipped Image'), imshow(flipdim(img, 1));
subplot(2,2,4), title('Left to right Flipped Image'), imshow(flipdim(img, 2));

/* c. Thresholding */

function bin_img = imthreshold(gray_img, d0)
bin_img = gray_img >= d0;
endfunction;

sam_img = imread('Test_images/wom1.jpg');

figure(n), n = n + 1;
subplot(1,2,1), title('Original Image'), imshow(sam_img);
subplot(1,2,2), title('Binary Image at D0 = 120'), imshow(imthreshold(sam_img, 120));

/* d. Contrast Stretching */

function [image, image1] = contrast_stretch(gray_img)
a = min(gray_img(:));
b = max(gray_img(:));
c = perctl(double(gray_img),[5,95]); // 5 & 95 percentile of image

image = (gray_img - c(1)).*((b-a)/(c(2)-c(1))) + a;
image1 = (gray_img - a)*(255/(b-a));
endfunction;

[c_sam, c_sam1] = contrast_stretch(sam_img);
   
figure(n), n = n + 1;    
subplot(321),title("Original Image "),imshow(sam_img);
subplot(322),title("Original Histogram"),imhist(sam_img,[],1);
subplot(323),title("Stretched Image 1"),imshow(c_sam);
subplot(324),title("Stretched Histogram 1"), plot2d3(imhist(c_sam));
subplot(325),title("Stretched Image 2"),imshow(c_sam1);
subplot(326),title("Stretched Histogram 2"), imhist(c_sam1,[], 1);

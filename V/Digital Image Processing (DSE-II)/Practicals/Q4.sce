/* Sample images */
n = 1
// for airthmetic, images have to be of same size
img1 = imread('Test_images/girlface.bmp');
img2 = imread('Test_images/lighthouse.bmp');

figure(n), n = n + 1;
subplot(1,2,1), title('Image 1'), imshow(img1);
subplot(1,2,2), title('Image 2'), imshow(img2);

figure(n), n = n + 1;
/* a. And operation on two images */
subplot(1,2,1), title('Image 1 & Image 2'), imshow(img1 & img2);

/* b. Or operation on two images */
subplot(1,2,2), title('Image 1 | Image 2'), imshow(img1 | img2);

/* c. Intersection of two images */
figure(n), n = n + 1;
inter_img = (double(img1) - double(img2)) == 0;
title('Intersection of Image 1 & Image 2'), imshow(inter_img);


/* d. NOT on the images */
figure(n), n = n + 1;
subplot(1,2,1), title('~(Image 1)'), imshow(~img1);
subplot(1,2,2), title('NOT of Image 2'), imshow(~img2);

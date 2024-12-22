/* Sample images */
n = 1
im1 = imread('Test_images/lena_1.jpeg');
im2 = imread('Test_images/measure.jpg');
im2 = imresize(im2, [225,225]);

figure(n), n = n + 1;
subplot(1,2,1), title('Image 1'), imshow(im1);
subplot(1,2,2), title('Image 2'), imshow(im2);

// a. use '+' between images or use imadd() method 
im3 = imadd(im1, im2);

// b. use '-' between images or use imsubtract() method 
im4 = im1 - im2;
im5 = im2 - im1;

figure(n), n = n + 1;
subplot(1,3,1), title('Image 3 = Image 1 + Image 2'), imshow(im3);
subplot(1,3,2), title('Image 4 = Image 1 - Image 2'), imshow(im4);
subplot(1,3,3), title('Image 5 = Image 2 - Image 1'), imshow(im5);

/*c. Mean of the images */

printf('Mean of the image 1 : %.3f\n',mean(im2double(im1)));
printf('Mean of the image 2 : %.3f',mean(im2double(im2)));

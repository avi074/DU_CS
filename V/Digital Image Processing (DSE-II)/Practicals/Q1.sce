/* a. Scilab Basic Commands */

disp('2 * 3 - 4 + 8 / 3 \ 9 =', 2*3-4+8/3\9);
n = 1
figure(n), n = n + 1;
x = linspace(0,8,100);
plot(sin(x),'o-');
plot(cos(x),'r.-');
xtitle('sin & cos waves');
legend('sin(x)','cos(x)', 3);
xgrid(0,1,7);

/* b. Reading & Displaying Image in Scilab */

img = imread("Test_images/balloons.png");
figure(n), n = n + 1;
imshow(img);

/* c. Resize given image */

printf("\nSize of the image : %i %i", size(img));
img1 = imresize(img,2);
printf("\n\nAfter Resizing the image by 2 : %i %i \n\n", size(img1));

/* d. RGB to Grayscale Image */

gray_img = rgb2gray(img);
figure(n), n = n + 1;
subplot(1,2,1), title('Original Image'), imshow(img);
subplot(1,2,2), title('Grayscale Image'), imshow(gray_img);

/* e. RGB to Grayscale Image */

bw_img = im2bw(img, 0.5);
figure(n), n = n + 1;
subplot(1,2,1), title('Original Image'), imshow(img);
subplot(1,2,2), title('B&W Image'), imshow(bw_img);

/* f. Drawing Image Profile */
figure(n), n = n + 2;
profile = improfile(img);

/* g. Seperating RGB Planes */

[r,c] = size(img); // no. of rows & columns of image

all_black = zeros(r,c,'uint8'); // A Black Image
// img(:,:,1) = red channel of image
red_img = cat(3, img(:,:,1), all_black, all_black);
// img(:,:,2) = green channel of image
green_img = cat(3,  all_black, img(:,:,2), all_black);
// img(:,:,3) = blue channel of image
blue_img = cat(3, all_black, all_black, img(:,:,3));

// plotting
figure(n), n = n + 1;
subplot(2,2,1),title("Original Image"),imshow(img);
subplot(2,2,2),title("Red Plane Image"),imshow(red_img);
subplot(2,2,3),title("Green Plane Image"),imshow(green_img);
subplot(2,2,4),title("Blue Plane Image"),imshow(blue_img);

/* h.  Creating image from RGB Planes */

// RGB Image = red + green + blue channels
merged = red_img + green_img + blue_img;
figure(n), n = n + 1;
subplot(3,3,2),title("Original Image"), imshow(img);
subplot(3,3,4),title("Red Plane Image"), imshow(red_img);
subplot(3,3,5),title("Green Plane Image"), imshow(green_img);
subplot(3,3,6),title("Blue Plane Image"), imshow(blue_img);
subplot(3,3,8),title("Merged RGB Planes Image"), imshow(merged);

/* i. Flow control & loop in scilab */
for i=1:10
    if modulo(i,2) == 1 then 
        disp(i);
    else
         continue;
    end,
end;

/* j. Create image with given 2D data */

mat_2d = modulo(round(rand(10,20) * (17/7) * 256),256);
disp('\n\nGiven 2D data : ', mat_2d);
figure(n), n = n + 1;
title('Created Image from matrix'), imshow(uint8(mat_2d));

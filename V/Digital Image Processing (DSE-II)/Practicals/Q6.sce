/* a. translation */





/* b. Scaling */
s_img = imread(fullpath(getIPCVpath() + "/images/puffin.png"));

width = size(s_img, 'c'); // column pixels = width
height = size(s_img, 'r'); // row pixels = height

// Scaling width by 2
w = 2;
h = 1;

mat = [ w 0;
        0 h;
        0 0];

sc1 = imtransform(s_img, mat, 'affine', width*w, height*h);

// Scaling height by 2
w = 1;
h = 2;

mat = [ w 0;
        0 h;
        0 0];

sc2 = imtransform(s_img, mat, 'affine', width*w, height*h);

// Scaling image by 2
w = 2;
h = 2;

mat = [ w 0;
        0 h;
        0 0];
        
sc3 = imtransform(s_img, mat, 'affine', width*w, height*h);

function s = str(img)
    s = 'Size : ' + strcat(string(size(img)), ' * '); 
endfunction;

figure(2);
subplot(331), title('Original Image'), xlabel(str(s_img)), imshow(s_img);
subplot(322), title('Image scaling width by 2'),xlabel(str(sc1)), imshow(sc1);
subplot(234), title('Image scaling height by 2'),xlabel(str(sc2)), imshow(sc2);
subplot(224), title('Image scaling by 2'),xlabel(str(sc3)), imshow(sc3);

/* c. Rotation */
figure(3);
subplot(2,2,1), title('Original Image'), imshow(s_img);
subplot(2,2,2), title('Image rotation by 45'), imshow(imrotate(s_img, 45));
subplot(2,2,3), title('Image rotaion by -45'), imshow(imrotate(s_img, -45));
subplot(2,2,4), title('Image rotaion by 180'), imshow(imrotate(s_img, 180));

// mdb (MinMax Based Detector) filter

// Original Image
grayImg = rgb2gray(imread('penguines.jpg'));
subplot(221), title("Original Image"), imshow(grayImg);
mini = min(grayImg(:));
maxi = max(grayImg(:));

// Noised Image
d_im = imnoise(grayImg, 'salt & pepper', 0.6);
subplot(222), title("Padded Noisy Image"), imshow(d_im);

// algorithm
[r c] = size(d_im);
img1 = zeros(r+2, c+2, 'uint8');
img1(2:r+1, 2:c+1) = d_im(:,:);

// border padded image
img1(1, 1) = d_im(1, 1);
img1(r+2, 1) = d_im(r, 1);
img1(1, c+2) = d_im(1, c);
img1(r+2, c+2) = d_im(r, c);

img1(2:r+1, 1) = d_im(:,1); 
img1(2:r+1, c+2) = d_im(:,c);
img1(1, 2:c+1) = d_im(1,:);
img1(r+2, 2:c+1) = d_im(r,:);

subplot(223), title("Median Filtered Image"), imshow(immedian(d_im,3));
for i = 2:r+1
    for j = 2:c+1
        if img1(i,j) <= mini  | img1(i,j) >= maxi then
            img1(i,j) = gsort(img1(i-1:i+1, j-1:j+1))(5); 
        end
    end
end
subplot(224), title("Denoised Image using mdb filter"), imshow(img1(2:r+1, 2:c+1));

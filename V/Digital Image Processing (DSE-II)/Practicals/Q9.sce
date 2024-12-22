S = rgb2gray(imread(fullpath(getIPCVpath() + "/images/baboon.png")));
h = mkfftfilter(S,'butterworth2',0.3);
h1 = 1.-h;
S2 = fft(im2double(S));
S3 = S2.*fftshift(h);
S4 = real(ifft(S3));
S5 = S2.*fftshift(h1);
S6 = real(ifft(S5));

imshow(S4);
figure(3);
imshow(S6);

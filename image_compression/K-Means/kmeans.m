% K-means

clear all; close all; clc;

A = double(imread('panda_s.jpg'));

dim = size(A,1);
k = 256; % cluster count : number of colors to represent

means = zeros(k, 3);
rand_x = ceil(dim*rand(k, 1));
rand_y = ceil(dim*rand(k, 1));
for i = 1:k
    means(i,:) = A(rand_x(i), rand_y(i), :);
endfor

nearest_mean = zeros(dim);

max_iterations = 150;
for itr = 1:max_iterations
    
    new_means = zeros(size(means));
    num_assigned = zeros(k, 1);
    
    for i = 1:dim
        for j = 1:dim
            r = A(i,j,1); g = A(i,j,2); b = A(i,j,3);
            diff = ones(k,1)*[r, g, b] - means;
            distance = sum(diff.^2, 2);
            [val ind] = min(distance);
            nearest_mean(i,j) = ind;
            
            new_means(ind, 1) = new_means(ind, 1) + r;
            new_means(ind, 2) = new_means(ind, 2) + g;
            new_means(ind, 3) = new_means(ind, 3) + b;
            num_assigned(ind) = num_assigned(ind) + 1;
        endfor
    endfor
    
    for i = 1:k
        % Only update the mean if there are pixels assigned to it
        if (num_assigned(i) > 0)
            new_means(i,:) = new_means(i,:) ./ num_assigned(i);
        endif
    endfor
    
    % Convergence test
    d = sum(sqrt(sum((new_means - means).^2, 2)));
    if d < 1e-5
        break
    endif
    
    means = new_means;
endfor
disp(itr) % iteration count unitl convergence

means = round(means);

large_image = double(imread('panda_l.jpg'));
large_dim = size(large_image, 1);

for i = 1:large_dim
    for j = 1:large_dim
        r = large_image(i,j,1); g = large_image(i,j,2); b = large_image(i,j,3);
        diff = ones(k,1)*[r, g, b] - means;
        distance = sum(diff.^2, 2);
        [val ind] = min(distance);
        large_image(i,j,:) = means(ind,:);
    endfor 
endfor
imshow(uint8(round(large_image))); hold off
imwrite(uint8(round(large_image)), 'panda_kmeans.jpg');

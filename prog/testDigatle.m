clc;
clear;
pic = imread('dig.gif'); %导入原始图像
figure(1);
imshow (pic)
title("original picture") %显示原始图像

%%  Binarization   
pic_bin = pic;  
pic_tem = pic;
for i = 1:size(pic,1)
    for j = 1:size(pic,2)
        if pic(i,j) > 100
            pic_bin(i,j) = 0;  %二值化,黑白反转图像
            pic_tem(i,j) = 1;%显示二值化并反转结果
        else
            pic_bin(i,j) = 1;%反转图像
            pic_tem(i,j) = 255;%显示二值化并反转结果
        end
    end
end

figure(2);
imshow(pic_tem)
title("Binarization")

%%  Cut   
pic_sum_collon = sum(pic_bin,2);%行和数组
pic_sum_row = sum(pic_bin);     %列和数组

num_collon = 0;  %行跳变数  ----期待值为18
num_row    = 0;  %列跳变数
loc        = zeros(20,2);  %跳变位置数组，第一列为行数第二列为列数

for i = 1:size(pic_sum_collon,1)-1  %行遍历
    if (pic_sum_collon(i)<50) && (pic_sum_collon(i+1)>50) && (pic_sum_collon(i+1)<600)  %当前为黑，下一行有白 且下一行非全白
        num_collon = num_collon + 1; %行数加一  
        loc(num_collon,1) = i+1; %记录行跳变位置
    end

    if (pic_sum_row(i)>50) && (pic_sum_row(i+1)<51) && (pic_sum_row(i)<600) %当前为黑，下一行有白 且下一行非全白
        num_row = num_row +1; %列数加一
        loc(num_row,2) = i;  %记录列跳变数
    end
end

% for i = 1:num_collon  %
%     eval(['pic_sub',num2str(i),'=pic_tem(loc(i,1):loc(i,2)+8,loc(i,1)+5:loc(i,2));']);%数字并非正方形因此需要调整
% end
pic_sub0 = pic_tem( loc(2,1) : loc(2,2)+8 , loc(1,1)+7 : loc(1,2) );
pic_sub1 = pic_tem( loc(2,1) : loc(2,2)+8 , loc(2,1)+6 : loc(2,2) );
pic_sub2 = pic_tem( loc(1,1) : loc(1,2)+7 , loc(6,1)+4 : loc(6,2) );
pic_sub3 = pic_tem( loc(1,1) : loc(1,2)+7 , loc(8,1)+10 : loc(8,2) );
pic_sub4 = pic_tem( loc(2,1) : loc(2,2)+8 , loc(3,1)+6 : loc(3,2) );
pic_sub5 = pic_tem( loc(2,1) : loc(2,2)+8 , loc(8,1)+10 : loc(8,2) );
pic_sub6 = pic_tem( loc(2,1) : loc(2,2)+8 , loc(4,1)+5 : loc(4,2) );
pic_sub7 = pic_tem( loc(2,1) : loc(2,2)+8 , loc(6,1)+4 : loc(6,2) );
pic_sub8 = pic_tem( loc(2,1) : loc(2,2)+8 , loc(7,1)+5 : loc(7,2) );
pic_sub9 = pic_tem( loc(2,1) : loc(2,2)+8 , loc(9,1)+5 : loc(9,2) );

figure(3);  %显示切割好的图像
title("pic sub")
for i = 1:10    
    subplot(2,5,i);
    eval(['imshow(','pic_sub',num2str(i-1),')']);
end


%% 放缩图像

%% 根据面积识别数字
for i = 0:9
    eval(['pic_sum',num2str(i),'=sum(sum(pic_sub',num2str(i),'));']);
end

% pic_sum = sum(sum(pic_sub1));



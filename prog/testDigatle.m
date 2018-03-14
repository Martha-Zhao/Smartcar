clc;
clear;
pic = imread('dig.gif'); %����ԭʼͼ��
figure(1);
imshow (pic)
title("original picture") %��ʾԭʼͼ��

%%  Binarization   
pic_bin = pic;  
pic_tem = pic;
for i = 1:size(pic,1)
    for j = 1:size(pic,2)
        if pic(i,j) > 100
            pic_bin(i,j) = 0;  %��ֵ��,�ڰ׷�תͼ��
            pic_tem(i,j) = 1;%��ʾ��ֵ������ת���
        else
            pic_bin(i,j) = 1;%��תͼ��
            pic_tem(i,j) = 255;%��ʾ��ֵ������ת���
        end
    end
end

figure(2);
imshow(pic_tem)
title("Binarization")

%%  Cut   
pic_sum_collon = sum(pic_bin,2);%�к�����
pic_sum_row = sum(pic_bin);     %�к�����

num_collon = 0;  %��������  ----�ڴ�ֵΪ18
num_row    = 0;  %��������
loc        = zeros(20,2);  %����λ�����飬��һ��Ϊ�����ڶ���Ϊ����

for i = 1:size(pic_sum_collon,1)-1  %�б���
    if (pic_sum_collon(i)<50) && (pic_sum_collon(i+1)>50) && (pic_sum_collon(i+1)<600)  %��ǰΪ�ڣ���һ���а� ����һ�з�ȫ��
        num_collon = num_collon + 1; %������һ  
        loc(num_collon,1) = i+1; %��¼������λ��
    end

    if (pic_sum_row(i)>50) && (pic_sum_row(i+1)<51) && (pic_sum_row(i)<600) %��ǰΪ�ڣ���һ���а� ����һ�з�ȫ��
        num_row = num_row +1; %������һ
        loc(num_row,2) = i;  %��¼��������
    end
end

% for i = 1:num_collon  %
%     eval(['pic_sub',num2str(i),'=pic_tem(loc(i,1):loc(i,2)+8,loc(i,1)+5:loc(i,2));']);%���ֲ��������������Ҫ����
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

figure(3);  %��ʾ�и�õ�ͼ��
title("pic sub")
for i = 1:10    
    subplot(2,5,i);
    eval(['imshow(','pic_sub',num2str(i-1),')']);
end


%% ����ͼ��

%% �������ʶ������
for i = 0:9
    eval(['pic_sum',num2str(i),'=sum(sum(pic_sub',num2str(i),'));']);
end

% pic_sum = sum(sum(pic_sub1));



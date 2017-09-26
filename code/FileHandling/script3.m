%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Description : Script to search for a substring in a given 
% string and to convert a string to lower case
% Author : Prabodh C P, Dept of CSE, SIT
% Date : 07/­12/­2013
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
clc;
str1=input('Enter String 1','s');
str2=input('Enter String 2','s');

fprintf('\nString 1 is\n');
disp(str1);
fprintf('\nString 2 is\n');
disp(str2);

k = strfind(str1, str2);
if k != 0
	fprintf('Match occurred at positions\n');
	disp(k);
else
	fprintf('Match does not occur\n');
end

low=lower(str1);
fprintf('\nOriginal String\n');
disp(str1);
fprintf('\nConverted String in lower case\n');
disp(low);


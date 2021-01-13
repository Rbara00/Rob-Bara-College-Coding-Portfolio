%Function by Antony Zheng
%
%Rules for player one when it is two players playing
%When player one enter his/her word, it will:
%- will take any cap letters and convert them into lower
%- numbers will be invalid
%- returns a corrected word
%

function inp=player1input()
clc;
clear;

inp = input('Enter a word: \n', 's'); %%ask for input

word = lower(inp);
charArray= char(word);
inp=charArray;
if(~isletter(charArray(1)))         %Checks if it is a number, otherwise it can include numbers
    while(~isletter(charArray(1)))  %such as 'got 2 go'
         charArray =input("Enter Valid Word: \n", 's');
    end
        charArray=char(lower(charArray));
        inp=charArray;             %outputs the valid player 1 word for player 2 to guess
end

end

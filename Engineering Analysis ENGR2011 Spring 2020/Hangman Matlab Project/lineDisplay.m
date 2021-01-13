% Function by Wenting Dong
%
% My function will take the input for the number of players then decide
% the game mode. Mode one with one player: take random word from the array
% in Hangman funtion then the word will be replace with '-' and return back
% to the command window for guessing. Mode two with two players: one
% player provides word in player1input function then the word will be
% replace with '-' and return back to the command window for player two to
% guess

function [Ans,lineString,flag]=lineDisplay(inputWord)
flag=0;
numPlayer=input('Please enter 1 or 2 for the number of player:\n');
% if it is one player
lineString={''};
if numPlayer== 1;
    num=strlength(inputWord);
   Ans=inputWord;
    for  i = 1:num
        lineString=strcat(lineString,"-");
    end
    disp(lineString);
    

else % two players
    word= player1input();%word input 
    size=length(word);
    Ans=word;
    display('Player 2, please guess the word.')
    for  i = 1:size
        if(isletter(word(i)))
    lineString=strcat(lineString,"-");
        else lineString=strcat(lineString,word(i)); flag=flag+1;          
        end
       if(isspace(word(i)))
            lineString=strcat(lineString,{' '}); flag=flag+1;
       end
    end
    disp(lineString); 
end
end

%If checking is true: 
%for loop over the word and input the characters into the word array?
%If checking is false: 
%i=i-1?Word = [c][h][e][c][k]?Word = [][][][][]?Word = [c][][][c][]?C _ _ C _

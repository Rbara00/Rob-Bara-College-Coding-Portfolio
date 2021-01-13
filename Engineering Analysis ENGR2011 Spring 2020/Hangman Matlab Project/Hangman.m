%Function by Zen
%
%Checks validity of guess input and reprompts if wrong.
%Uses output from other functions to determine validity of guesses
%Keeps track of # of right and wrong letters
%Call with empty parameters to run hangman game
function hangmanInputCheck()
clc
clf
init(); 
WrongCt=0;
RightCt=0;

StringArray={'fast','yikes','analysis'};
StringArrayRand=StringArray(randi([1,3],1,1));

[Answer,dashes,ct]=lineDisplay(StringArrayRand); %%%Wendy's function call
ct;
dashArray=char(dashes)
wordChar=char(Answer);

while(WrongCt<6)       %Runs as 6 maximum wrong guesses are allowed
    

a=0;
    while(~isletter(a))     %When entering an invalid guess, re-prompt
    a=lower(input('Enter a Letter!\n','s'));
     if(length(a)~=1)
        a=0;
     end
    end
if(length(a)==1&&isletter(a))   %If the input is a letter and 
    if(contains(Answer,a(1)));  %is in the word, add to right counter
    RightCt=RightCt+1;
     for i=1:length(dashArray)
        if(a==wordChar(i))
            dashArray(i)=a
        end
     end
    else WrongCt=WrongCt+1; disp("Wrong guess!"); 
         lynch(WrongCt);  %Otherwise, it is counted as wrong
    end
  

end
    if(ct>0&&RightCt==length(wordChar)-ct)  %Takes number of nonletters in word and excludes them
    disp("YOU WIN")                     % from having to be guessed
    break
    else
        if(RightCt==length(wordChar))          %if Right guesses is the length of word, you win
          disp("YOU WIN")
         break
        end
    end
end
end

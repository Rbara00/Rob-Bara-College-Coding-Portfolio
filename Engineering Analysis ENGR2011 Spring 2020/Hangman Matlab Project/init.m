%Function init by Robert Bara 
%
%This function initializes the hangman board by using lines drawn in matlab
%and objects to customize the width and color of the line
function initlynch = init(); 
    % Borders around the game
    X = [0 9];
    Y = [0 0];
    Z = [9 9]; %Creates an Axis/frame
    Frame1=line (X,Y); %Bottom Frame
    Frame2=line (Y,X); %Left Frame
    Frame3=line (X,Z); %Top Frame
    Frame4=line (Z,X); %Right Frame
    Frame1.LineWidth=2;
    Frame2.LineWidth=2;
    Frame3.LineWidth=2;
    Frame4.LineWidth=2;
    Frame1.Color='k';
    Frame2.Color='k';
    Frame3.Color='k';
    Frame4.Color='k';
    %Initalizing the Lynching without the man
    pole= line([7 7],[0 7.05]); %first [ ] is x-axis, second is height
    pole.LineWidth = 4;
    pole.Color = 'b'; 
               
    pole_top = line([6.5 7],[7.5 7]); 
    pole_top.LineWidth = 4.5; 
    pole_top.Color = 'b';

    pole_top2 = line([5 6.55],[7.5 7.5]);
    pole_top2.LineWidth=4;
    pole_top2.Color='b';

    pole_top3 = line([5.5 5.5],[6.7 7.5]);
    pole_top3.LineWidth=3;
    pole_top3.Color ='b';
    
    stage=line([4 8], [.2 .2]);
    stage.LineWidth= 10;
    stage.Color ='b';

end
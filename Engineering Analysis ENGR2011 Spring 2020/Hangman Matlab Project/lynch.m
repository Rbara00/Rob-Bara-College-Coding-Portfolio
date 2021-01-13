%Function lynch by Robert Bara
%
%Using a Switch Statement this function uses lines and objects to draw a
%body part for each case upon a wrong guess, starting with head, torso, right arm, left
%arm,left leg, and finally right leg/face/game over
function Drawing=lynch(graphic)
    %Drawing the stick man
    switch(graphic)
        case 1
            head = [5 5.7 1 1];
            rectangle('Position',head,'Curvature',[1 1])
            axis equal
        case 2
            torso=line([5.5 5.5],[4 5.7]);
            torso.Color='r';
        case 3
            rightarm=line([5.5 6.2],[5.3 5.5]);
            rightarm.Color='r';
        case 4
            leftarm=line([5.5 4.8],[5.3 5.5]);
            leftarm.Color='r';
        case 5
            legleft=line([5.5 5],[4 3.2]);
            legleft.Color='r';
        case 6    
            legright=line([5.5 6],[4 3.2]);
            legright.Color='r';
        
            lefteyeR=line([5.4 5.2], [6.4 6.3]);
            lefteyeL=line([5.2 5.4], [6.4 6.3]);
            lefteyeR.Color='r';
            lefteyeL.Color='r';

            righteyeR=line([5.6 5.8], [6.4 6.3]);
            righteyeL=line([5.8 5.6], [6.4 6.3]);
            righteyeR.Color='r';
            righteyeL.Color='r';

            mouth=line([5.4 5.6], [6 6]);
            mouth.Color='k';
            fprintf("\tYou Lose :( \n");
        end %of switch
end

for k=1:10
    Map = dlmread('level_template.map');
    for i=1:15
        for j=1:15
            if Map(i,j) == 3
                Map(i,j) = randi([0 10],1,1);
                if Map(i,j) > 0
                    Map(i,j) = randi([4 5],1,1);
                    if Map(i,j) == 5 
                        Map(i,j) = randi([5 9],1,1);
                    end
                end
            end
        end
    end
dlmwrite(strcat('level', num2str(k), '.map'), Map, ' ');
end
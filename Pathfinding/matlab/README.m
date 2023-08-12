%% Function descriptions
%% To view a map, given a map file

viewmap('c/map_1.txt',0); % shows walls
viewmap('c/map_1.txt',1); % shows track

%or else

[m]=map_convert('c/map_1.txt');
plotmap(m);
%Here   'm' is the map file returned as a matrix
[rows, cols] = size(m);
startloc = get_random_location(rows, cols, m);
targetloc = get_random_location(rows, cols, m);

% Your simulations will use this structure
[m,v,s]=dijkstra('maps/map_8.txt',[startloc],[targetloc]);
%Here   'm' is the map file returned as a matrix
%       'v' is a matrix that shows which cells have been visited, '0' means
%       visited, '1' means not visited
%       's' is the vector of steps to reach the target,
%       [startloc] is a vector i.e. [2,2]
%       [targetloc] is also a vector ie [4,18]

%To view the path determined above use 
plotmap(m,s);

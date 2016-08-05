# csc418_3D_Game
A 3D bird flying game;Try to collect white balls and avoid red balls. Using keyboard A,W,S,D to control direction and using I,K to move forward and backward.
- No points, game exits when red ball touches you.
- White/Red balls have a speed that is away/towards your position.
- Move around by turning up/down/left/right and moving forward/back.
- Walls and ceiling bound the area and are texture mapped.
- Wall is one image split into 4 parts for each wall.
- Ceiling is just another image since no good free environment map images were found.
- Ground uses some ground making to get hills and valleys.
- Different heights at each point and connect together to form a sort of ground mesh.
- Grass texture is put on each quadrilateral tile.
- Colour of each tile is attenuated by its slope to simulate shadows/foreshortening.
- The bird tilts when turning.

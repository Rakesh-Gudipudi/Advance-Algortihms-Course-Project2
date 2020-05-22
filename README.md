# Project2-CPSC535
<ins>**Introduction:**</ins>

In this project an algorithm related to hash tables is implemented. project is about reading a large number of distinct product numbers (7-digit each) and deciding which digit among the seven gives the best balanced storage of the items. 

<ins>**Choosing the hash function:**</ins>

At an optometrist store, glasses of various sizes and shapes are displayed in a glass display that has 10 cubbies or sections. Each pair of glasses is unique and has a 7-digit barcode. You have too many pairs of glasses to store them in the same cubby, plus only few would be visible. You are tasked with organizing the pairs of glasses into cubbies such that most of them are visible. You came up with an idea of storing the pairs of glasses based on a single digit of their product number. So you try to group them based on the first digit, second digit, .., seventh (and last digit). (The digits are read from left to right; e.g. for the number 8976565, the first digit is 8, the second is 9, the third is 7, the fourth is 6, the fifth is 5, the sixth is 6 and the seventh and last is 5.) You settle on the digit that gives the best “balancing” of storing the pairs of glasses, i.e., the difference between the number of pairs of glasses in the most populated cubby and the least populated cubby is minimized among all possible five options.

Project is about reading a large number of distinct product numbers (7-digit each) and deciding which digit among the seven gives the best balanced storage of the pairs of glasses.
For example, let’s assume that we have the following product numbers:
1234567, 2345678, 3456789, 4567890, 5678901, 6789012, 7890123, 8901234, 9012345, 5432109, 6543210, 7654321, 8765432, 9876543, 1098765, 2109876, 3210987, 4321098
If we choose storing the bows based on the first digit that we have:
Cubby 0: no pair of glasses
Cubby 1: 1234567, 1098765
Cubby 2: 2345678, 2109876
….
Cubby 9: 9012345, 9876543
The difference in the cubbies’ load is 2.

If we choose storing based on the second digit:
Cubby 0: 9012345, 1098765
Cubby 1: 2109876
Cubby 2: 1234567 
…
Cubby 9: 8901234, 
The difference in the cubbies’ load is 1 so clearly this is a more balanced organization of the pair of glasses.


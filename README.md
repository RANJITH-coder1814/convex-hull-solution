Problem Statement

You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.

Return the coordinates of trees that are exactly located on the fence perimeter.
You may return the answer in any order.

Example
Example 1
Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Example 2
Input: trees = [[1,2],[2,2],[4,2]]
Output: [[1,2],[2,2],[4,2]]
Approach

This problem is solved using the Monotonic Chain Convex Hull Algorithm.

Idea
Sort all points based on x-coordinate and y-coordinate.
Build:
Lower Hull
Upper Hull
Use cross product to determine clockwise or counterclockwise turns.
Include all boundary points on the convex hull.

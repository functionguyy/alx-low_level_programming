#!/usr/bin/python3
"""Module contains function island_perimeter()

    Usage: island_perimeter(grid)
"""


def count_water_edges(x, y, matrix):
    """count edges of a grid cell touching water
    0 represents a water zone
    1 represents a land zone
    One cell is a square with side lenght 1
    """

    grid_height = len(matrix)
    grid_width = len(matrix[x])
    count = 0

    # count water edges
    if y - 1 == 0 or grid[y - 1][x] == 0:
        count += 1
    if x + 1 == grid_width or grid[y][x + 1] == 0:
        count += 1
    if y + 1 == grid_height or grid[y + 1][x] == 0:
        count += 1
    if x - 1 = 0 or grid[y][x - 1] == 0:
        count += 1

    return count


def island_perimeter(grid):
    """returns the perimeter of the island described in grid

       grid: list of list of integers
    """

    # check that grid is a list of list of integers that doesn't exceed height
    # and width of 100
    if type(grid) is list:
        if len(grid) > 100:
            return 0
        for element in grid:
            if len(element) > 100:
                return 0
            if type(element) is not list:
                return 0
            for item in element:
                if type(item) is not int:
                    return 0
    else:
        return 0


    perimeter = 0
    for row_num in range(len(grid)):
        row = grid[row_num]
        for col_num in range(len(row)):
            if grid[row_num][col_num] == 1:
                perimeter += count_water_edges(col_num, row_num, grid)

    return perimeter

from Quoridor import *


class Point(object):
    def __init__(self, owner, location):
        self.owner = owner
        self.location = location
        if self.owner is 0:
            self.destination = 6
            self.h = self.destination - location[0]
        else:
            self.destination = 0
            self.h = location[0]
        self.g = 0
        self.f = 0


class SearchRouteBoard(object):
    def __init__(self):
        self.close_list = []
        self.open_list = []


def search_path(owner, origin, testBoard):
    """
    search path length with AStar
    :param owner: whose's turn
    :param origin: start location
    :param testBoard: board now
    :return: length of route
    """
    temp = 1
    sonPointInOpenlistFlag = 0
    searchPoint = Point(owner, origin)
    neighbor = testBoard.possible_piece_location(searchPoint.location)
    for i in neighbor:
        sonPointInOpenlistFlag = 0
        sonPoint = Point(owner, i)
        sonPoint.fatherPoint = searchPoint.location
        sonPoint.g = searchPoint.g + 1
        sonPoint.f = sonPoint.g + sonPoint.h

        if sonPoint.location[0] == searchPoint.destination:
            temp = 0
            break
        for searchRepeat in testBoard.openList:
            if sonPoint.location == searchRepeat.location:
                sonPointInOpenlistFlag = 1
                if sonPoint.g < searchRepeat.g:
                    searchRepeat.fatherPoint = searchPoint.location
                    searchRepeat.g = searchPoint.g + 1
                    searchRepeat.f = searchRepeat.g + searchRepeat.h
                break
        if not sonPointInOpenlistFlag:
            testBoard.openList.append(sonPoint)

        minimalSearch = 0x3f3f3f3f
        for tempPoint in testBoard.openList:
            if tempPoint.f <= minimalSearch:
                searchPoint = tempPoint
                minimalSearch = tempPoint.f
        testBoard.openList.remove(searchPoint)
        testBoard.closeList.append(searchPoint)
        tempPoint = testBoard.closeList[-1]
        result = [tempPoint.location]

    while not (tempPoint.location == origin):
        result.append(tempPoint.fatherPoint)
        for i in reversed(testBoard.closeList):
            if i.location == tempPoint.fatherPoint:
                tempPoint = i
                testBoard.closeList.remove(i)
                break

    testBoard.openList = []
    testBoard.closeList = []
    return len(result) - 1  # return distance


if __name__ == "__main__":
    test_board = SearchRouteBoard()
    l = search_path(0, (0, 0), test_board)
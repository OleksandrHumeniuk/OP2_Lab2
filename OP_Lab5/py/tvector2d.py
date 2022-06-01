from tvector import TVector
from math import sqrt


class TVector2D(TVector):
    def __init__(self, x, y):
        self.__x = x
        self.__y = y

    def getScalar(self, other):
        return self.__x * other.getCoordinate("x") + self.__y * other.getCoordinate("y")

    def getLength(self):
        return sqrt(self.__x * self.__x + self.__y * self.__y)

    def getCoordinate(self, c):
        if c == "x":
            return self.__x
        elif c == "y":
            return self.__y
        else:
            return 0

    def print(self, header):
        print(f"{header} TVector2D: x = {self.__x:5} y = {self.__y:5}")

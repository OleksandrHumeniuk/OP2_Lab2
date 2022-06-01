from abc import ABC, abstractmethod


class TVector(ABC):
    @abstractmethod
    def getScalar(self, other):
        pass

    @abstractmethod
    def getLength(self):
        pass

    @abstractmethod
    def getCoordinate(self, c):
        pass

    @abstractmethod
    def print(self, header):
        pass

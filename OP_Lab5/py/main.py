from functions import inputTVector2D, inputTVector3D

if __name__ == "__main__":
    lst = [inputTVector3D("Enter information for 3D Vector A"),
           inputTVector3D("\nEnter information for 3D Vector B"),
           inputTVector2D("\nEnter information for 2D Vector C"),
           inputTVector2D("\nEnter information for 2D Vector D")]

    lst[0].print("\nVector A ->")
    lst[1].print("Vector B ->")
    lst[2].print("Vector C ->")
    lst[3].print("Vector D ->")

    S = lst[0].getScalar(lst[1]) + lst[2].getScalar(lst[3]) + lst[0].getLength()
    print(f"\nResult of calculations S: {S:.2f}")

#%%

import numpy as np

# %%

arr = np.array([1,2,3])

# print(type(arr[0]))

arr2 = np.array(10)
# print(arr2)

arr3 = np.array([[1, 2, 3], [4, 5, 6]])
# print(arr3.shape)

array3d = np.array([[[1, 2], [3, 4]], [[5, 6], [7, 8]], [[9,10],[11,12]]])

print()
# %%
print(array3d[0,0,0])
# %%

z = np.zeros((2,3))
print("Zeros:")
print(z)
ones = np.ones((2,3))
print("Ones:")
print(ones)
full = np.full((2,3), 5)
print("Full:")
print(full)
arrange = np.arange(0,100,5)
print("Arrange:")
print(arrange)
eye = np.eye(5)
print("Eye:")
print(eye)


print("Slice")
arr2d = np.array([[1,2,5,6],[5,9,2,3]])
print(arr2d[0,2:3])
print(arr2d[0:2:2])
print(arr2d.dtype)


arr = np.array([1,2,5,6])

arr_c = arr.copy()
arr_v=arr.view()

arr_c[0] = 9
arr_v[0] = 8
print(arr)
# print(arr_v)
print(arr_c)


# %%
print(arr2d.shape)
arr3d = arr2d.reshape((2,2,2))
print(arr3d)

# %%

newArr = np.array([1,5,9,3,2,1,5,6])

newArr3d = newArr.reshape((2,2,2))

newArr3d2 = newArr.reshape((2,1,4))

print(newArr3d)
# print(newArr3d2)

# %%

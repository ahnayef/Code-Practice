#%%

li = ["A", 1, 2.5, 0.5]
tp = ("A", 1, 2.5)

# tp[0] = "B" # not allowed, tuples are immutable

#%%
print(li)
print(tp)

tp1=list(tp)

tp1[0] = "B"
print(tp1)
# %%

st = {'A', 1, 2.5, 2.5}

print(st)

st[0] = "B"  # not allowed, sets are unordered and do not support indexing

# %%
st1 = set(tp1)
print(st1)
# %%

dt = {
     "name": "AHN",
     "id" : 1234,
     "id": 5678
}
print(dt)
dt["id"] = 91011
print(dt)
# %%

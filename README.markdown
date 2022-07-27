# lua binding for wyhash

```lua
local wyhash = require("wyhash")
local seed = 20
local sec = wyhash.make_secret(seed)
print(wyhash.hash("sasasa", seed, sec))
print(wyhash.hash("sasasa", seed, sec))
print(wyhash.hash("sasasa", seed+1, sec))
print(wyhash.hash("sasasa", seed+1, sec))
print(wyhash.hash("sasasa", seed+2, sec))
print(wyhash.hash("sasasa", seed+2, "ssssssssssssssssssssssssssssssss"))
```
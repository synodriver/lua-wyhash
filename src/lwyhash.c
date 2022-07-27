#include <stdint.h>

#include "lua.h"
#include "lauxlib.h"

#include "wyhash.h"

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#elif
#define DLLEXPORT
#endif /* _WIN32 */


static int
lmake_secret(lua_State *L)
{
    if (lua_gettop(L) != 1)
    {
        return luaL_error(L, "must have a seed");
    }
    uint64_t seed = (uint64_t) luaL_checkinteger(L, 1);
    uint64_t _wyp[4];
    make_secret(seed, _wyp);
    lua_pushlstring(L, (const char *) _wyp, 32);
    return 1;
}

static int
lhash(lua_State *L)
{
    if (lua_gettop(L) != 3)
    {
        return luaL_error(L, "must have data, seed and secret");
    }
    size_t size, secret_size;
    void *data = (void *) luaL_checklstring(L, 1, &size);
    uint64_t seed = (uint64_t) luaL_checkinteger(L, 2);
    uint64_t *secret = (uint64_t *) luaL_checklstring(L, 3, &secret_size);
    if(secret_size!=32)
    {
        return luaL_error(L, "secret must have 32 bytes");
    }
    uint64_t ret = wyhash(data, size, seed,secret);
    lua_pushinteger(L, (lua_Integer)ret);
    return 1;
}


static luaL_Reg lua_funcs[] = {
        {"make_secret", &lmake_secret},
        {"hash",        &lhash},
        {NULL, NULL}
};

DLLEXPORT int luaopen_wyhash(lua_State *L)
{
    luaL_newlib(L, lua_funcs);
    return 1;
}
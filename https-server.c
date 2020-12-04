#include <util/base.h>
#include <windows.h>
#include <http.h>

static ULONG retCode;
static PHANDLE* hReqQueue;

void init() 
{	
	HTTPAPI_VERSION HttpApiVersion = HTTPAPI_VERSION_1;
    retCode = HttpInitialize(HttpApiVersion, HTTP_INITIALIZE_SERVER, NULL);

    if (retCode != NO_ERROR)
    {
        wprintf(L"HttpInitialize failed with %lu \n", retCode);
        return retCode;
    }

    //
    // Create a Request Queue Handle
    //
    retCode = HttpCreateHttpHandle(
        &hReqQueue,        // Req Queue
        0                  // Reserved
    );

    if (retCode != NO_ERROR)
    {
        wprintf(L"HttpCreateHttpHandle failed with %lu \n", retCode);
        cleanUp();
    }
}

ULONG cleanUp() {
    //
    // Call HttpRemoveUrl for all added URLs.
    //
    for (int i = 1; i <= UrlAdded; i++)
    {
        HttpRemoveUrl(
            hReqQueue,     // Req Queue
            argv[i]        // Fully qualified URL
        );
    }

    //
    // Close the Request Queue handle.
    //
    if (hReqQueue)
    {
        CloseHandle(hReqQueue);
    }

    // 
    // Call HttpTerminate.
    //
    HttpTerminate(HTTP_INITIALIZE_SERVER, NULL);

    return retCode;
}
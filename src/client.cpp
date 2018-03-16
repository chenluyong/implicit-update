#include "client.h"
#include <direct.h>
#include <iostream>

#include "server.h"
#include "file.h"
namespace oe {

class OEClientPrivate {
public:
    OEClientPrivate(OEClient* const _parent)
        :q_ptr(_parent) {
    }

    Q_DECLARE_PUBLIC(OEClient)
    class OEClient* q_ptr;


private:
    std::string appPath_;
};


OEClient::OEClient(void)
    :d_ptr(new OEClientPrivate(this))
{
    // get current version
}

int OEClient::update(void)
{
    //
    Q_D(OEClient);

    // get work dir
    if (d->appPath_.empty()) {
        char app[255] = {};
        getcwd(app, sizeof(app));
        d->appPath_ = app;
    }

    // up all file
    updateLocalFileInfo();

    // get app version

    return OELIB_SUCCESS;
}

int OEClient::traverseRoute(const std::string &_filePath,
                            const _finddata32_t &_fileData)
{
    Q_D(OEClient);
    std::string file_name =  _filePath + "\\" + _fileData.name;
    size_t pos = _filePath.find(d->appPath_.c_str(),0);
    if (pos == std::string::npos)
        return OELIB_ERROR;
    file_name.erase(file_name.begin(), file_name.begin() + d->appPath_.length());

    if (file_name.at(0) == '\\'
        || file_name.at(0) == '/')
        file_name.erase(file_name.begin());
#if OELIB_DEBUG < 2
    std::cout << file_name.c_str() << std::endl;
#endif

    OEFile file(file_name, OEFile::LOCAL);
    addFile(file);

    return OELIB_SUCCESS;
}

int OEClient::updateLocalFileInfo()
{
    Q_D(OEClient);
    // check app path
    if (d->appPath_.empty()) {
#if defined(_DEBUG) || OELIB_DEBUG < 5
        std::cerr << "app path can't be empty" << std::endl;
#endif
        return OELIB_ERROR;
    }
    // clear file info cache
    setAllFile({});

    return traverseDir(d->appPath_);

}

int OEClient::traverseDir(const std::string &_dir)
{
    std::string dir_new = _dir + "\\*.*";

    intptr_t handle;
    _finddata_t file_data;

    handle = _findfirst(dir_new.c_str(), &file_data);
    // check file
    if (handle == -1)
        return OELIB_ERROR;

    do
    {
        if (file_data.attrib & _A_SUBDIR)
        {
            if (strcmp(file_data.name, ".") == 0 || strcmp(file_data.name, "..") == 0)
                continue;

            // add to directory "\\"
            dir_new = _dir + '\\' + file_data.name;
            traverseDir(dir_new);
        }
        else
            traverseRoute(_dir, file_data);

    } while (0 == _findnext(handle, &file_data));


    _findclose(handle);
    return OELIB_SUCCESS;
}

}

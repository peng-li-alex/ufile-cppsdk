#ifndef _UFILESDK_CPP_UCLOUD_API_PUT_
#define _UFILESDK_CPP_UCLOUD_API_PUT_

#include <istream>
#include <ufile-cppsdk/apibase.h>

namespace ucloud {
namespace cppsdk {
namespace api {

struct PutResult {
  uint64_t set_id;           // 文件set_id
};

class UFilePut : public APIBase {

public:
  UFilePut();
  ~UFilePut();

  /*
   * @brief: 上传文件
   * @bucket: 目标Bucket名称
   * @key: 保存在Bucket上的文件对象名称
   * @is: 输入流
   * @result: 要保存返回结果的PutResult对象的地址
   * @return: 0=成功，非0=失败
   */
  int Put(const std::string &bucket, const std::string &key, std::istream &is,
          PutResult *result);
  /*
   * @brief: 上传文件
   * @bucket: 目标Bucket名称
   * @key: 保存在Bucket上的文件对象名称
   * @ptr: 数据指针
   * @size: 数据长度
   * @result: 要保存返回结果的PutResult对象的地址
   * @return: 0=成功，非0=失败
   */
  int Put(const std::string &bucket, const std::string &key, const char *ptr,
          const size_t size, PutResult *result);
  /*
   * @brief: 上传文件
   * @bucket: 目标Bucket名称
   * @key: 保存在Bucket上的文件对象名称
   * @is: 输入流
   * @result: 要保存返回结果的PutResult对象的地址
   * @return: 0=成功，非0=失败
   */
  int PutFile(const std::string &bucket, const std::string &key,
              const std::string &filepath, PutResult *result);

private:
  int ParseRsp(const char *header, PutResult *result);
  std::string m_filename;
};

} // namespace api
} // namespace cppsdk
} // namespace ucloud

#endif

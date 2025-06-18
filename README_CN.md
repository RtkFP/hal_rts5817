# 使用方法

1. 参考 https://docs.zephyrproject.org/latest/develop/getting_started/index.html 配置好zephyr开发环境
2. `git clone`该仓库到与zephyr同级的目录，如下：
   ```shell
   ├── bootloader
   ├── hal_rts5817
   ├── modules
   ├── tools
   └── zephyr
   ```
3. 编译时可以通过`DEXTRA_ZEPHYR_MODULES`这个参数来指定该module，如下：
   ```shell
   west build -b rts5817_maa_evb/rts5817 zephyr/samples/hello_world -- -DEXTRA_ZEPHYR_MODULES=/<path>/hal_rts5817
   ```
   > **注意:**`DEXTRA_ZEPHYR_MODULES`的路径是绝对路径

   也可以在zephyr仓库的west.yml文件上加上该module，如下
   ```shell
   diff --git a/west.yml b/west.yml
   index 702bc9b784e..bd8e68344d9 100644
   --- a/west.yml
   +++ b/west.yml
   @@ -232,6 +232,8 @@ manifest:
     - name: hal_rpi_pico
       path: modules/hal/rpi_pico
       revision: 7b57b24588797e6e7bf18b6bda168e6b96374264
   +    - name: hal_rts5817
   +      path: hal_rts5817
       groups:
         - hal
     - name: hal_silabs
   ```
   然后再使用如下命令编译
   ```shell
   west build -b rts5817_maa_evb/rts5817 zephyr/samples/hello_world
   ```
   这样就不需要通过`DEXTRA_ZEPHYR_MODULES`来指定module的路径
4. 使用`west flash`命令进行烧写
   >**注意：**
   >1. 该命令只适用于Linux主机
   >2. 烧写时需要让IC进入force rom mode

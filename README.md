# User Guide

1. Configure the zephyr development environment with the reference implementation of https://docs.zephyrproject.org/latest/develop/getting_started/index.html
2. `git clone` the repository to the same directory as zephyr, as follows：
   ```shell
   ├── bootloader
   ├── hal_rts5817
   ├── modules
   ├── tools
   └── zephyr
   ```
3. You can use this Zephyr module by setting `DEXTRA_ZEPHYR_MODULES`，as follows：
   ```shell
   west build -b rts5817_maa_evb/rts5817 zephyr/samples/hello_world -- -DEXTRA_ZEPHYR_MODULES=/<path>/hal_rts5817
   ```
   > **Note:** The path to `DEXTRA_ZEPHYR_MODULES` is an absolute path.

   You can also add this module to the west.yml file in the zephyr repository, as follows:
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
   Then building by using the following command:
   ```shell
   west build -b rts5817_maa_evb/rts5817 zephyr/samples/hello_world
   ```
   In this way, there is no need to specify the module path through `DEXTRA_ZEPHYR_MODULES`.
4. You can use `west flash` command to re-build the binary and flash it to your board.
   >**Note：**
   >1. This command is only supported on Linux hosts.
   >2. The IC needs to enter force rom mode while flashing.

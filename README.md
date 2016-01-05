sunxi-tools
-----------

Tools to help hacking Allwinner A10 (aka sun4i) ans A20 (aka sun7i) based devices and possibly their successors, that's why the 'x' in the package name.


Building the tools
------------------
By default, the configure script will detect the buid environment and decide what set of tools to build. On an ARM platform, all the tools will be build, on any other platform, just the architecture independent tools will be build.

    ./configure
    make

To build sunxi-fel, libusb-1.0 must be avalable on the system. It is also not possible to cross-compile sunxi-fel with this build system. 

    apt-get install libusb-1.0-0-dev

You can cross-compile the tools by specifying the `--host` switch, the proper toolchain must be avalable on the system. See https://linux-sunxi.org/Cross_Compiler for more informations on how to install the toolchain.

    ./configure --host=arm-linux-gnueabihf
    make

To build the bare-metal tools, use the '--with-baremetal' switch when running configure.

    ./configure --with-baremetal
    make

To install the tools, just do a `make install` once everything is build. To change the default installation path, use the `--prefix` switch.

    ./configure --host=arm-linux-gnueabihf --prefix=/home/user/arm-build/usr
    make
    make install

See `./configure --help` for more information on the build process and all avalable parameters.

Architecture independent tools
------------------------------
Theses tools can run natively on the device or offline on another device, they can be build for any CPU architecture.

###sunxi-fexc
`.fex` file (de)compiler, utility to (de)compile fex/bin format files used by Allwinners's sdk to configure board's options under kernel 3.4.

    Usage: sunxi-fexc [-vq] [-I <infmt>] [-O <outfmt>] [<input> [<output>]]
    
    infmt:  fex, bin  (default:fex)
    outfmt: fex, bin, uboot  (default:bin)

###sunxi-bin2fex
Compatibility shortcut to call `fexc` to decompile a binary blob blob back into `.fex` format.

    Usage: sunxi-bin2fex [-vq] [<binary file> [<fex file>]]

###sunxi-fex2bin
Compatiblity shortcut to call `fexc` to compile a `.fex` file to blob used by sunxi kernel.

    Usage: sunxi-fex2bin [-vq] [<fex file> [<binary file>]]

###sunxi-nand-part
Tool for manipulating Allwinner NAND partition tables or NAND image file.

    usage: sunxi-nand-part [options]
    Options:
      --help                   Display this information
    
      --type=<TYPE>            Specify device type
      --device                 Specify NAND device (default: /dev/nand)
    
      --clean                  Create an empty MBR
      --backup=<FILE>          Backup MBR to FILE
      --restore=<FILE>         Restore MBR to FILE
    
      --partition=<OPTIONS>    Modify a partition, <OPTIONS> are a comma-separated
                               list made of the following items:
        add=<PARAMS>           Add, a partition
        insert=<ID>,<PARAMS>   Insert a partition at <ID>
        delete=<ID>            Delete partition <ID>
    
        Parameters for add/insert:
        start=<BLOCK>          Starting block of the partition
        length=<BLOCKS>        Length of the partition in bocks (-1, use wathever is left)
        class=<CLASS>          Class ID of the partition (default: DISK)
        name=<NAME>            Name of the partition
        ro                     Partition should be flagged Read-Only

###sunxi-bootinfo
Dump information from Allwinner boot files (boot0/boot1)

    Usage: sunxi-bootinfo --type=<sd|nand> <FILENAME>
    
      --type=sd         include SD boot info
      --type=nand       include NAND boot info (not implemented)

###sunxi-phoenix_info
Gives information about a phoenix image created by the phoenixcard utility and optionally extracts the embedded boot code & firmware file from their hidden partitions.

    Usage: sunxi-phoenix_info [options] [phoenix_image]
       -v      verbose
       -q      quiet
       -p N    part number
       -o X    destination directory, file or pattern (%d for part number)
       -s      save all parts
	

Architecture dependent tools
----------------------------
Theses tools are dependent of hardware functions of SUNXI devices and are only build when cross-compiling or compiling natively on an ARM device.

###sunxi-meminfo
Tool for reading DRAM settings from registers. Compiled as a static binary for use on android and other OSes.

    Usage: sunxi-meminfo [OPTION]
      Options:
        -f: print in FEX format (default).
        -u: print in sunxi U-Boot dram.c file format.
        -h: print this usage information.

###sunxi-script_extractor
A simple tool, which can be executed on a rooted Android device to dump the script.bin blob from RAM via reading /dev/mem.

###sunxi-pio
Tool for manipulating the GPIO of a device.

    usage: sunxi-pio -m|-i input [-o output] pin..
      -m                             mmap - read pin state from system
      -i                             read pin state from file
      -o                             save pin state data to file
      print                          Show all pins
      Pxx                            Show pin
      Pxx<mode><pull><drive><data>   Configure pin
      Pxx=data,drive                 Configure GPIO output
      Pxx*count                      Oscillate GPIO output (mmap mode only)
      Pxx?pull                       Configure GPIO input
      clean                          Clean input pins
    
      mode 0-7, 0=input, 1=ouput, 2-7 I/O function
      pull 0=none, 1=up, 2=down
      drive 0-3, I/O drive level


Library dependent tools
-----------------------
Theses tools are dependent of specific libraries and will only build if the library is avalable natively on the builder system (not cross-compiling).

###sunxi-fel
script interface for talking to the FEL USB handler built into the CPU. You activate FEL mode by pushing the usboot/recovery button at poweron. See http://linux-sunxi.org/FEL/USBBoot for a detailed usage guide.

    Usage: sunxi-fel [options] command arguments... [command...]
      -v, --verbose                   Verbose logging
      -p, --progress                  "write" transfers show a progress bar
    
        spl file                        Load and execute U-Boot SPL
                        If file additionally contains a main U-Boot binary
                        (u-boot-sunxi-with-spl.bin), this command also transfers that
                        to memory (default address from image), but won't execute it.
    
        uboot file-with-spl             like "spl", but actually starts U-Boot
                        U-Boot execution will take place when the fel utility exits.
                        This allows combining "uboot" with further "write" commands
                        (to transfer other files needed for the boot).
        
        hex[dump] address length        Dumps memory region in hex
        dump address length             Binary memory dump
        exe[cute] address               Call function address
        read address length file        Write memory contents into file
        write address file              Store file contents into memory
        write-with-progress addr file   "write" with progress bar
        write-with-gauge addr file      Output progress for "dialog --gauge"
        write-with-xgauge addr file     Extended gauge output (updates prompt)
        multi[write] # addr file ...    "write-with-progress" multiple files,
                                        sharing a common progress status
        multi[write]-with-gauge ...     like their "write-with-*" counterpart,
        multi[write]-with-xgauge ...    but following the 'multi' syntax:
                                        <#> addr file [addr file [...]]
        echo-gauge "some text"          Update prompt/caption for gauge output
        ver[sion]                       Show BROM version
        clear address length            Clear memory
        fill address length value       Fill memory

###sunxi-fel-gpio
Simple wrapper around sunxi-pio and sunxi-fel to allos GPIO manipulations via FEL


Bare Metal Tools
----------------
Theses tools are for bare-metal (no operating system) use, they are not normally build, to build them, use the --with-baremetal when you run configure.

###sunxi-fel-copy
ARM native tool to copy a memory area to another.

###sunxi-fel-pio
ARM native helper for sunxi-fel-gpio

###sunxi-fel-sdboot
ARM native sdcard bootloader forcing the device into FEL mode

###sunxi-jtag-loop.sunxi
ARM native boot helper to force the SD port into JTAG and then stop, to ease debugging of bootloaders.

###sunxi-boot_head_sun4i.bin
ARM native shim to fix incorrect board ID on sun4i device

###sunxi-boot_head_sun5i.bin
ARM native shim to fix incorrect board ID on sun5i device

This software is licensed under the terms of GPLv2+ as defined by the Free Software Foundation, details can be read in the COPYING file.

See AUTHOR for a complete list of authors and copyright.


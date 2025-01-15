# Stack Virtual Machine & Full Virtual Machine Setup Guide 🎛️

**Overview** 👉 This repo contains my **Stack Virtual Machine** project & instructions on setting up a full system simulation VM on Windows 11 
(which I will use to test my cryptography and antimalware software).


---


## **Stack Virtual Machine from scratch** 🛠️  ---

**Why build it?** 👉 Building this simple VM will help me understand how VMs operate on a low level, allowing me to learn more about registers, memory management, and instruction sets adding to the fundamentals built from my university module on Computer Systems & X86 Assembly. 

### Goals for This Project  
1. Create a fully functional Stack VM with:  
   - Arithmetic operations.  
   - Basic branching instructions (e.g., `jump`, `call`, `return`).  
   - Simple I/O handling.  
2. Document the process for learning and reference.  

### Developer Notes
- My VM runs on a 32-bit CPU. An 8-bit CPU could perform operations in single cycles on values from 0 to 255. A 16-bit processor could do the same on values between 0 and 65535, something the 8-bit processor would only achieve after several cycles. The number only increases with 32 and 64-bit processors. I don't need any more processing power than what my 32-bit architecture delivers for a simple Stack VM, which is why I will stick to it.

- The VM runs on C++.


---


## **Setting Up a Full VM on Windows 11** ⚙️ ---

This guide provides step-by-step instructions for setting up a virtual machine on Windows 11 using different methods. Choose the one that suits your needs.

‼️ *Keep in mind that running viruses on VMs like Windows Sandbox is still risky, since there are cleverly written malware that are smart enough to detect a sandboxed environment and behave innocuously (i.e., exploits might be hidden or time delayed). Running something in a sandbox (and observing no negative side effects) does not guarantee it is safe to run again on the host.*

---

## **Method 1: Using Hyper-V (Built-in on Windows 11 Pro, Enterprise, and Education)**

### **Step 1: Enable Hyper-V**
1. **Check system requirements**:
   - A 64-bit processor with SLAT (Second Level Address Translation).
   - CPU support for virtualization (Intel VT-x or AMD-V).
   - At least 4 GB of RAM.

2. **Enable virtualization in BIOS/UEFI**:
   - Restart your computer and enter BIOS/UEFI (press `F2`, `F10`, `DEL`, or similar during boot).
   - Enable virtualization options (`Intel Virtualization Technology` or `AMD-V`).
   - Save and exit.

3. **Enable Hyper-V in Windows**:
   - Press `Windows + R`, type `optionalfeatures`, and press Enter.
   - Check the box for **Hyper-V** in the **Windows Features** window.
   - Click **OK** and restart your PC.


### **Step 2: Create a Virtual Machine in Hyper-V**
1. Open **Hyper-V Manager**:
   - Press `Windows`, search for "Hyper-V Manager," and open it.

2. Create a new virtual machine:
   - In the right pane, click **New > Virtual Machine**.
   - Follow the wizard to:
     - Name your VM and set a location.
     - Select **Generation 1** (legacy) or **Generation 2** (modern).
     - Allocate memory (e.g., 4 GB for most OSes).
     - Configure networking with a virtual switch.
     - Specify a virtual hard disk size (e.g., 50 GB).
     - Select installation media (ISO file).

3. Start the VM:
   - Right-click the VM, select **Connect**, and click **Start**.
   - Install your operating system.

---

## **Method 2: Using VirtualBox (Free Third-Party Tool)**

### **Step 1: Download and Install VirtualBox**
1. Visit the [VirtualBox website](https://www.virtualbox.org/) and download the installer for Windows.
2. Install VirtualBox, following the prompts.
3. Install the **VirtualBox Extension Pack** for additional features.


### **Step 2: Create a Virtual Machine**
1. Launch VirtualBox.
2. Click **New** and configure:
   - Name, type, and version (e.g., Windows 11, Linux).
   - Allocate memory size.
   - Create a virtual hard disk (choose VDI format, dynamic or fixed size).


### **Step 3: Configure the Virtual Machine**
1. Right-click the VM, select **Settings**, and adjust:
   - **System**: Enable hardware virtualization.
   - **Storage**: Attach the ISO file under "Controller: IDE."
   - **Network**: Use NAT or Bridged adapter.


### **Step 4: Start the Virtual Machine**
1. Select the VM and click **Start**.
2. Follow the OS installation steps.

---

## **Method 3: Using VMware Workstation Player**

### **Step 1: Download VMware Workstation Player**
1. Visit the [VMware website](https://www.vmware.com/products/workstation-player.html) and download the free version.
2. Install VMware Workstation Player.


### **Step 2: Create a New Virtual Machine**
1. Launch VMware Player and click **Create a New Virtual Machine**.
2. Select the installation media (ISO file or physical disc).
3. Assign resources (CPU, RAM, disk size).
4. Complete the wizard and start the VM.

---

## **Method 4: Using Windows Sandbox (Quick and Lightweight)**

### **Step 1: Enable Windows Sandbox**
1. Press `Windows + R`, type `optionalfeatures`, and press Enter.
2. Check the box for **Windows Sandbox** in the **Windows Features** window.
3. Click **OK** and restart your PC.


### **Step 2: Launch Windows Sandbox**
1. Press `Windows`, search for "Windows Sandbox," and open it.
2. A clean, disposable Windows 11 environment will launch.
   - Any changes you make in the sandbox are discarded when it is closed.

---

## Conclusion
Choose the method that best fits your needs:
- **Hyper-V**: For advanced users with Windows 11 Pro or higher.
- **VirtualBox**: Free and versatile.
- **VMware Workstation Player**: User-friendly and feature-rich.
- **Windows Sandbox**: Fast, lightweight, and disposable.


---


## Contributing 🌱
Feel free to fork this repo and open pull requests for improvements or additional features. 

❕ Original project belongs to Philip Bohun 👉 https://www.youtube.com/playlist?list=PLSiFUSQSRYAOFwfP-aMzXJlWKVyIuWfPU, I followed his tutorial to learn C++ syntax and see exactly how a stack vm would work.

## License  
This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.

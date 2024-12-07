# Stack Virtual Machine & Full Virtual Machine Setup Guide 🎛️

**Overview** 👉 This repo contains my **Stack Virtual Machine** project & instructions on setting up a full system simulation VM on Windows 11 
(which I will use to test my cryptography and antimalware software).

---

## // **Stack Virtual Machine from scratch** 🛠️ 

**Why build it?** 👉 Building this simple VM will help me understand how VMs operate on a low level, allowing me to learn more about registers, memory management, and instruction sets adding to the fundamentals built from my university module on Computer Systems & X86 Assembly. 

### Goals for This Project  
1. Create a fully functional Stack VM with:  
   - Arithmetic operations.  
   - Basic branching instructions (e.g., `jump`, `call`, `return`).  
   - Simple I/O handling.  
2. Document the process for learning and reference.  
3. Extend functionality with a small "programming language" for testing.

### Developer Notes
- My VM runs on an 8-bit CPU. It can perform operations in single cycles on values from 0 to 255. A 16-bit processor could do the same on values between 0 and 65535, something my 8-bit processor would only achieve after several cycles. The number only increases with 32 and 64-bit processors, however, I will stick to the 8-bit architecture since I don't need any additional processing power for a simple Stack VM.

- The VM will run in X86 Assembly with C++.

- 

---

## // **Setting Up a Full VM on Windows 11** ⚙️

### Prerequisites  
Before you begin, ensure you have the following:  
- **Windows 11** installed.  
- A copy of a virtualization tool (e.g., VirtualBox or VMware Workstation Player).  
- ISO file for the operating system you want to install in the VM.  

---

### Steps to Set Up a Virtual Machine  (in progress)

1. **step 1**  

---

## Contributing 🌱
Feel free to fork this repo and open pull requests for improvements or additional features.  

## License  
This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.

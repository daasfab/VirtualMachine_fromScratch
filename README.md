# Stack Virtual Machine & Full Virtual Machine Setup Guide 🎛️

**Overview** 👉 This repo contains my **Stack Virtual Machine** project & instructions on setting up a full system simulation VM on Windows 11 
(which I will use to test my cryptography and antimalware software).

---

## **Stack Virtual Machine from scratch** 🛠️ 

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

## **Setting Up a Full VM on Windows 11** ⚙️ (in progress...)

1. **Download 64-bit Windows 11 ISO** https://www.microsoft.com/en-us/software-download/windows11
   <div align="center">
     <img src="📸 Set-up Process Screenshots/Download.png" alt="screenshot" style="width: 10000px; margin-bottom: -10px;">
   </div>
   
2. **Enable the HyperVisor Software of Choice**
   I will be using Hyper-V. To enable it on your Windows device type this into PowerShell:
   
   ```
   Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Hyper-V -All
   ```
   
3. 

---

## Contributing 🌱
Feel free to fork this repo and open pull requests for improvements or additional features.  

## License  
This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.




// MainBASE 클래스 정의
class DllLoadCollector {
public:


    DllLoadCollector();
    ~DllLoadCollector();
    static void LoadSyntaxAIWebModule();
    static void ProcessModuleFunctions();
    static DWORD WINAPI MainStart(LPVOID lpParam);
    static char* Big_pointer_pch;
    static DWORD WINAPI ExecuteClonedFunction(LPVOID functionParam);
    // 함수 포인터: DLL에서 복제된 함수를 실행하기 위한 포인터
    static int (*GetDllFunctionClone)(LPVOID functionParam);


public:

};



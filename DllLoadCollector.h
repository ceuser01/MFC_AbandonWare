


// MainBASE Ŭ���� ����
class DllLoadCollector {
public:


    DllLoadCollector();
    ~DllLoadCollector();
    static void LoadSyntaxAIWebModule();
    static void ProcessModuleFunctions();
    static DWORD WINAPI MainStart(LPVOID lpParam);
    static char* Big_pointer_pch;
    static DWORD WINAPI ExecuteClonedFunction(LPVOID functionParam);
    // �Լ� ������: DLL���� ������ �Լ��� �����ϱ� ���� ������
    static int (*GetDllFunctionClone)(LPVOID functionParam);


public:

};



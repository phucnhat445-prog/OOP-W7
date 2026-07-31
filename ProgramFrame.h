class ProgramFrame {
protected:
    virtual void startMessage(std::ostream& os) const;

    virtual void Input(std::istream& is) = 0;
    virtual bool Check() const = 0;

    virtual void errorMessage(std::ostream& os) const;

    virtual void Process() = 0;
    virtual void Output(std::ostream& os) const = 0;

    virtual bool askContinue(
        std::istream& is,
        std::ostream& os
    ) const;

public:
    virtual ~ProgramFrame();

    // Template Method: lớp cha cố định trình tự thực hiện.
    void run(std::istream& is, std::ostream& os);
};

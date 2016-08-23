#ifndef TESTITAGAINSAM_H_
#define TESTITAGAINSAM_H_

class TestItAgainSam {
public:
	TestItAgainSam();
	virtual ~TestItAgainSam();

	void Run() const;
	void TestHeaderInit() const;

	void TestLegacyContainers() const;
	void TestContainers() const;

	void TestLegacy42() const;
	void Test42() const;

	void TestLegacyEnums() const;
	void TestEnums() const;

	void TestAsync() const;

	void TestMove() const;

	void TestLambdas() const;
	void TestDoubles() const;
};

#endif /* TESTITAGAINSAM_H_ */

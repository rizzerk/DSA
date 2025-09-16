#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BATCHES 5  // Reduced for easier testing of full queue
#define MAX_SAMPLES 50

typedef struct {
    int sampleID;
    float features[4]; // 4 features per sample
    char label[20];    // Classification label
    float confidence;  // Model's confidence in prediction (0.0 - 1.0)
} TrainingData;

typedef struct {
    TrainingData batch[MAX_SAMPLES]; // Fixed-size array for batch data
    int count; // Number of samples in this batch
    int batchID;
    char status[20]; // "PENDING", "PROCESSING", "COMPLETED", "FAILED"
} DataBatch;

typedef struct {
    DataBatch batches[MAX_BATCHES]; // Circular array implementation
    int front;     // Points to the first batch to be processed
    int rear;      // Points to the last batch added
    int size;      // Current number of batches in queue
    int capacity;  // Maximum capacity (MAX_BATCHES)
} TrainingPipeline;

typedef struct {
    int totalBatches;
    int processedBatches;
    int failedBatches;
    float averageAccuracy;
    char modelName[50];
} MLMetrics;

// Completed Functions
void displayPipeline(TrainingPipeline *tp);
void displayMetrics(MLMetrics metrics);
DataBatch createSampleBatch(int batchID);
DataBatch createInvalidBatch();
void runComprehensiveTests();

// PROBLEM 0 - Basic Queue Operations
TrainingPipeline initPipeline();
int isEmpty(TrainingPipeline *tp);
int isFull(TrainingPipeline *tp);
void enqueueBatch(TrainingPipeline *tp, DataBatch newBatch);

// PROBLEM 1 - Processing Operations  
DataBatch dequeueBatch(TrainingPipeline *tp);
DataBatch peekNextBatch(TrainingPipeline *tp);
int getQueueSize(TrainingPipeline *tp);

// PROBLEM 2 - ML-Specific Operations
void processBatch(TrainingPipeline *tp, MLMetrics *metrics);
void validatePipeline(TrainingPipeline *tp);
MLMetrics calculateMetrics(TrainingPipeline *tp);

int main() {
    srand(42); // Fixed seed for consistent testing
    
    printf("=== COMPREHENSIVE ML PIPELINE TEST SUITE ===\n");
    printf("Testing ALL edge cases for Circular Array Queue\n\n");
    
    runComprehensiveTests();
    
    return 0;
}

void runComprehensiveTests() {
    TrainingPipeline pipeline;
    MLMetrics metrics;
    DataBatch batch;
    
    // ==================== TEST 1: EMPTY QUEUE OPERATIONS ====================
    printf("TEST 1: Empty Queue Operations\n");
    printf("======================================\n");
    
    // TODO: Initialize pipeline and test empty queue operations
    // 1. Initialize pipeline
    // 2. Test isEmpty() and isFull() on empty queue
    // 3. Try to dequeue from empty queue (should show error)
    // 4. Try to peek from empty queue (should show error)  
    // 5. Try to process batch from empty queue (should show error)
    // 6. Display empty pipeline
    
    
    
    
    
    printf("\nPress any key for Test 2...\n");
    getch();
    system("cls");
    
    // ==================== TEST 2: SINGLE ELEMENT OPERATIONS ====================
    printf("TEST 2: Single Element Operations\n"); 
    printf("======================================\n");
    
    // TODO: Test queue with exactly one element
    // 1. Add one batch to empty pipeline
    // 2. Test size, isEmpty, isFull
    // 3. Peek at the batch (should not remove it)
    // 4. Verify size is still 1 after peek
    // 5. Dequeue the batch 
    // 6. Verify pipeline is empty after dequeue
    
    
    
    
    
    printf("\nPress any key for Test 3...\n");
    getch(); 
    system("cls");
    
    // ==================== TEST 3: FULL QUEUE OPERATIONS ====================
    printf("TEST 3: Full Queue Operations\n");
    printf("======================================\n");
    
    // TODO: Test completely full queue
    // 1. Fill pipeline to capacity (MAX_BATCHES = 5)
    // 2. Verify isFull() returns true
    // 3. Try to add another batch (should fail with error message)
    // 4. Display full pipeline
    // 5. Dequeue one batch
    // 6. Verify isFull() now returns false
    // 7. Add one more batch successfully
    
    
    
    
    
    printf("\nPress any key for Test 4...\n");
    getch();
    system("cls");
    
    // ==================== TEST 4: CIRCULAR WRAPAROUND ====================
    printf("TEST 4: Circular Array Wraparound\n");
    printf("======================================\n");
    
    // TODO: Test circular array wraparound behavior
    // 1. Fill pipeline with 3 batches (ID: 1,2,3)
    // 2. Display pipeline (front=0, rear=2)
    // 3. Dequeue 2 batches (front moves to 2) 
    // 4. Add 4 more batches (ID: 4,5,6,7) - rear should wraparound
    // 5. Display pipeline - should show wraparound with rear < front
    // 6. Verify all batch IDs are correct
    
    
    
    
    
    printf("\nPress any key for Test 5...\n"); 
    getch();
    system("cls");
    
    // ==================== TEST 5: FILL-EMPTY-FILL CYCLE ====================
    printf("TEST 5: Fill-Empty-Fill Cycle\n");
    printf("======================================\n");
    
    // TODO: Test multiple complete cycles
    // 1. Fill pipeline completely (5 batches)
    // 2. Empty pipeline completely  
    // 3. Verify pipeline is empty and pointers reset correctly
    // 4. Fill pipeline again with new batch IDs
    // 5. Verify second fill works correctly
    
    
    
    
    
    printf("\nPress any key for Test 6...\n");
    getch();
    system("cls");
    
    // ==================== TEST 6: BATCH PROCESSING - ALL SUCCESS ====================
    printf("TEST 6: Batch Processing - All Success Scenario\n");
    printf("======================================\n");
    
    // TODO: Test processing where all batches succeed
    // 1. Initialize metrics with model name "Test-AllSuccess"
    // 2. Add 3 batches to pipeline
    // 3. Process all batches (modify processBatch to force success)
    // 4. Calculate and display final metrics
    // 5. Validate pipeline
    
    
    
    
    
    printf("\nPress any key for Test 7...\n");
    getch();
    system("cls");
    
    // ==================== TEST 7: BATCH PROCESSING - ALL FAILURE ====================
    printf("TEST 7: Batch Processing - All Failure Scenario\n");
    printf("======================================\n");
    
    // TODO: Test processing where all batches fail
    // 1. Initialize metrics with model name "Test-AllFailure"  
    // 2. Add 3 batches with invalid data using createInvalidBatch()
    // 3. Process all batches (should all fail)
    // 4. Calculate and display final metrics (should show 0% success)
    // 5. Validate pipeline (should detect issues)
    
    
    
    
    
    printf("\nPress any key for Test 8...\n");
    getchcar();
    system("cls");
    
    // ==================== TEST 8: MIXED PROCESSING RESULTS ====================
    printf("TEST 8: Mixed Processing Results\n");
    printf("======================================\n");
    
    // TODO: Test processing with mixed success/failure
    // 1. Initialize metrics with model name "Test-Mixed"
    // 2. Add mix of valid and invalid batches
    // 3. Process all batches
    // 4. Calculate metrics (should show partial success)
    // 5. Validate pipeline
    
    
    
    
    
    printf("\n=== ALL COMPREHENSIVE TESTS COMPLETED ===\n");
}

// ==================== YOUR IMPLEMENTATIONS ====================

// Initialize the training pipeline
// Set front and rear to -1, size to 0, capacity to MAX_BATCHES
TrainingPipeline initPipeline() {
    // TODO: Implement this function
    TrainingPipeline tp;
    tp.front = -1;
    tp.rear =-1;
    tp.size = 0;
    tp.capacity = MAX_BATCHES;
}

// Check if the pipeline is empty
// Return 1 if empty, 0 otherwise
int isEmpty(TrainingPipeline *tp) {
    // TODO: Implement this function
    return tp->front == -1;
}

// Check if the pipeline is full  
// Return 1 if full, 0 otherwise
int isFull(TrainingPipeline *tp) {
    // TODO: Implement this function
    return (tp->rear + 1) % MAX_BATCHES == tp->front;
}

// Add a new batch to the pipeline
// Handle circular array logic properly
// Print appropriate messages for success/failure
void enqueueBatch(TrainingPipeline *tp, DataBatch newBatch) {
    // TODO: Implement this function
    // Remember to handle:
    // 1. Full queue case
    // 2. First element case (when queue is empty)
    // 3. Circular wraparound for rear pointer
    // 4. Update size
    // 5. Print appropriate messages

    if(isFull(tp)){
        printf("ERROR: Pipeline is full! Cannot add batch %d\n", newBatch.batchID);
        return;
    }else{
        if(isEmpty(tp)){
           tp->front = tp->rear = 0; 
        } else{
            tp->rear = (tp->rear + 1) % MAX_BATCHES;
        }

        tp->batches[tp->rear] = newBatch;
        tp->size++;
        printf("Batch %d successfully added to pipeline!\n");
    }

    
}

// Remove and return the next batch from the pipeline
// Handle circular array logic and empty queue cases
// Set status to "PROCESSING" when dequeued
DataBatch dequeueBatch(TrainingPipeline *tp) {
    // TODO: Implement this function
    // Remember to handle:
    // 1. Empty queue case (return dummy batch)
    // 2. Update front pointer with wraparound
    // 3. Decrease size
    // 4. Change status to "PROCESSING"
    // 5. Print appropriate messages
    
    
}

// Return the next batch without removing it from the pipeline
// Handle empty queue case
DataBatch peekNextBatch(TrainingPipeline *tp) {
    // TODO: Implement this function
    // Should not modify the queue, just return copy of front batch
    
}

// Return the current number of batches in the pipeline
int getQueueSize(TrainingPipeline *tp) {
    // TODO: Implement this function
    
}

// Process the next batch in the pipeline
// Dequeue a batch, simulate processing, update metrics
// For testing: check if batchID is negative to force failure
void processBatch(TrainingPipeline *tp, MLMetrics *metrics) {
    // TODO: Implement this function
    // 1. Check if pipeline is empty
    // 2. Dequeue next batch
    // 3. Simulate processing (use batchID < 0 to force failure)
    // 4. Update batch status to "COMPLETED" or "FAILED"
    // 5. Update metrics accordingly
    // 6. Print processing results
    
}

// Validate the pipeline for any inconsistencies
// Check for batches stuck in "PROCESSING" status
void validatePipeline(TrainingPipeline *tp) {
    // TODO: Implement this function
    // 1. Check if pipeline is empty
    // 2. Count batches in each status
    // 3. Look for batches stuck in "PROCESSING" 
    // 4. Print validation results
    
}

// Calculate overall metrics based on processed batches
MLMetrics calculateMetrics(TrainingPipeline *tp) {
    // TODO: Implement this function
    // 1. Count completed vs failed batches
    // 2. Calculate success rate
    // 3. Calculate average accuracy (use batch confidence values)
    // 4. Return populated metrics struct
    
}

// ==================== PROVIDED HELPER FUNCTIONS ====================

// DO NOT TOUCH - Creates a sample batch with random data
DataBatch createSampleBatch(int batchID) {
    DataBatch batch;
    batch.batchID = batchID;
    batch.count = (rand() % 20) + 10; // 10-30 samples per batch
    strcpy(batch.status, "PENDING");
    
    char labels[][20] = {"Iris-setosa", "Iris-versicolor", "Iris-virginica"};
    
    for(int i = 0; i < batch.count && i < MAX_SAMPLES; i++) {
        batch.batch[i].sampleID = batchID * 100 + i;
        
        // Random features (simulating iris dataset)
        batch.batch[i].features[0] = 4.0 + (float)(rand() % 40) / 10.0;
        batch.batch[i].features[1] = 2.0 + (float)(rand() % 25) / 10.0;  
        batch.batch[i].features[2] = 1.0 + (float)(rand() % 60) / 10.0;
        batch.batch[i].features[3] = 0.1 + (float)(rand() % 25) / 10.0;
        
        strcpy(batch.batch[i].label, labels[rand() % 3]);
        batch.batch[i].confidence = 0.7 + (float)(rand() % 30) / 100.0;
    }
    
    return batch;
}

// DO NOT TOUCH - Creates an invalid batch for failure testing
DataBatch createInvalidBatch() {
    DataBatch batch;
    batch.batchID = -1; // Negative ID to trigger failure
    batch.count = 0;    // No samples
    strcpy(batch.status, "CORRUPTED");
    return batch;
}

// DO NOT TOUCH - Displays current pipeline status
void displayPipeline(TrainingPipeline *tp) {
    printf("\n========= TRAINING PIPELINE STATUS =========\n");
    printf("Pipeline Capacity: %d\n", tp->capacity);
    printf("Current Size: %d\n", tp->size);
    printf("Front Index: %d | Rear Index: %d\n", tp->front, tp->rear);
    
    if(isEmpty(tp)) {
        printf("Pipeline is currently EMPTY\n");
        printf("==========================================\n\n");
        return;
    }
    
    printf("\n%-8s %-10s %-12s %-8s\n", "Position", "BatchID", "Status", "Samples");
    printf("------------------------------------------\n");
    
    int current = tp->front;
    for(int i = 0; i < tp->size; i++) {
        printf("%-8d %-10d %-12s %-8d\n", 
               current, 
               tp->batches[current].batchID,
               tp->batches[current].status,
               tp->batches[current].count);
        current = (current + 1) % tp->capacity;
    }
    printf("==========================================\n\n");
}

// DO NOT TOUCH - Displays ML metrics
void displayMetrics(MLMetrics metrics) {
    printf("\n========= ML TRAINING METRICS =========\n");
    printf("Model: %s\n", metrics.modelName);
    printf("Total Batches: %d\n", metrics.totalBatches);
    printf("Processed: %d\n", metrics.processedBatches);
    printf("Failed: %d\n", metrics.failedBatches);
    printf("Success Rate: %.2f%%\n", 
           metrics.totalBatches > 0 ? 
           (float)(metrics.processedBatches - metrics.failedBatches) / metrics.totalBatches * 100 : 0);
    printf("Average Accuracy: %.2f%%\n", metrics.averageAccuracy);
    printf("======================================\n\n");
}